window.onload = (event) => {
    // add padding top to show content behind navbar
    let navbar_height = document.querySelector('header').offsetHeight;
    document.body.style.paddingTop = navbar_height + 'px';
}