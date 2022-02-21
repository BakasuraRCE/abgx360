"""
html-minifier wrapper for Pelican
"""

import glob
import os
import sys
import subprocess

from pelican import signals

cmd = ['./node_modules/.bin/html-minifier', '--config-file', 'html-minifier.conf']


def process_file(file_path: str) -> None:
    try:
        subprocess.run(cmd + [file_path, '--output', file_path], stderr=subprocess.DEVNULL, check=True)
        print('OK:', file_path, os.getcwd())
    except subprocess.CalledProcessError:
        print('ERROR:', file_path, os.getcwd())


def main(pelican):
    print(pelican.path)
    for f in glob.iglob(pelican.output_path + '/**/*.htm*', recursive=True):
        process_file(f)
    for f in glob.iglob(pelican.output_path + '/**/*.css', recursive=True):
        process_file(f)
    # for f in glob.iglob(pelican.output_path + '/**/*.js', recursive=True):
    #     if f.endswith('min.js'):
    #         continue
    #     process_file(f)


def register():
    signals.finalized.connect(main)
