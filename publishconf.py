import sys

sys.path.append('.')
from pelicanconf import *

SITEURL = 'https://abgx360.bakasura.im'
JINJA_GLOBALS['SITEURL'] = SITEURL

PLUGINS += ['html-minifier']
