import sys

sys.path.append('.')
from pelicanconf import *

SITEURL = 'https://bakasurarce.github.io/abgx360'
JINJA_GLOBALS['SITEURL'] = SITEURL

PLUGINS += ['html-minifier']
