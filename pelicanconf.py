from jinja_config.filters import menu_order

# Site
DEFAULT_LANG = 'en'
AUTHOR = 'Bakasura'
SITENAME = 'abgx360 Reloaded'
SUBTITLE = 'Verify the integrity of your Xbox 360 game backups'
SITEURL = ''
TIMEZONE = 'EST'
THEME = 'darktheme'
GOOGLE_ANALYTICS = 'GTM-K5ZHTLX'
GITHUB_URL = 'https://github.com/BakasuraRCE/abgx360'
DISCORD_URL = 'https://discord.gg/Pn6A9YegXV'
DISPLAY_CATEGORIES_ON_MENU = False
DEFAULT_PAGINATION = 10

# Sitemap
SITEMAP = {
    "format": "xml"
}

# Slugs
PAGE_URL = '{slug}.html'
PAGE_SAVE_AS = PAGE_URL

# Filesystem
DIRECT_TEMPLATES = ['index']
ARTICLE_PATHS = ['articles']
STATIC_PATHS = ['static']
PATH = 'content'
EXTRA_PATH_METADATA = {
    'static/google791025052fdf886c.html': {'path': 'google791025052fdf886c.html'},
    'static/robots.txt': {'path': 'robots.txt'},
    'static/favicon.ico': {'path': 'favicon.ico'},
}

# Jinja
JINJA_FILTERS = {'menu_order': menu_order}

# Markdown
MARKDOWN = {
    'extension_configs': {
        'markdown.extensions.codehilite': {'css_class': 'highlight'},
        'markdown.extensions.extra': {},
        'markdown.extensions.attr_list': {},
        'markdown.extensions.meta': {},
        'markdown.extensions.toc': {'permalink': True},
    },
    'output_format': 'html5',
}

# Disable feed
FEED_ALL_ATOM = None
CATEGORY_FEED_ATOM = None
TRANSLATION_FEED_ATOM = None
AUTHOR_FEED_ATOM = None
AUTHOR_FEED_RSS = None

# # Blogroll
# LINKS = (('Pelican', 'https://getpelican.com/'),
#          ('Python.org', 'https://www.python.org/'),
#          ('Jinja2', 'https://palletsprojects.com/p/jinja/'),
#          ('You can modify those links in your config file', '#'),)

# # Social widget
# SOCIAL = (('You can add links in your config file', '#'),
#           ('Another social link', '#'),)

# Uncomment following line if you want document-relative URLs when developing
# RELATIVE_URLS = True
