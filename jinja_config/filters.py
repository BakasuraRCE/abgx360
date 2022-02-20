from operator import attrgetter


def menu_order(pages):
    for page in pages:
        if not hasattr(page, 'menu_order'):
            page.menu_order = 9999
        else:
            page.menu_order = int(page.menu_order)

        if not hasattr(page, 'menu_title'):
            page.menu_title = page.title

    return sorted(pages, key=attrgetter('menu_order', 'menu_title'))
