"""
html-minifier wrapper for Pelican
"""

import glob
import subprocess

from pelican import signals

cmd_html_minifier = ['./node_modules/.bin/html-minifier', '--config-file', 'html-minifier.conf']
cmd_terser = ['./node_modules/.bin/terser', '--comments', 'false']
cmd_cleancss = ['./node_modules/.bin/cleancss', '-O1', 'specialComments:0']


def process_file(file_path: str) -> None:
    try:
        if file_path.endswith('.js'):
            subprocess.run(cmd_terser + [file_path, '-o', file_path], stderr=subprocess.DEVNULL, check=True)
        elif file_path.endswith('.css'):
            subprocess.run(cmd_cleancss + [file_path, '-o', file_path], stderr=subprocess.DEVNULL, check=True)
        else:
            subprocess.run(cmd_html_minifier + [file_path, '--output', file_path], stderr=subprocess.DEVNULL, check=True)
    except subprocess.CalledProcessError:
        print('ERROR:', file_path)


def main(pelican):
    print(pelican.path)
    for f in glob.iglob(pelican.output_path + '/**/*.htm*', recursive=True):
        process_file(f)
    for f in glob.iglob(pelican.output_path + '/**/*.css', recursive=True):
        process_file(f)
    for f in glob.iglob(pelican.output_path + '/**/*.js', recursive=True):
        if f.endswith('min.js'):
            continue
        process_file(f)


def register():
    signals.finalized.connect(main)
