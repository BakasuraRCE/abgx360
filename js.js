function ver_MouseOverTR(tr) {
    tr.style.backgroundColor = '#464A6B';
}

function ver_MouseOutTR(tr) {
    tr.style.backgroundColor = '';
}

$(function () {
    $(".file-links a, .sub-file-links a").hover(
        function () {
            $(this).closest('.download-box').toggleClass('active')
        }
    )
})