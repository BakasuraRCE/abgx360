function check_del(translationid) {
	if (document.forms["translations"].elements["del[]"].length > 1) {
		for (var i=0; i < document.forms["translations"].elements["del[]"].length; i++) {
			if (document.forms["translations"].elements["del[]"][i].value == translationid) {
				document.forms["translations"].elements["del[]"][i].checked = (!document.forms["translations"].elements["del[]"][i].checked);
				break;
			}
		}
	}
	else {
		if (document.forms["translations"].elements["del[]"].value == translationid) {
			document.forms["translations"].elements["del[]"].checked = (!document.forms["translations"].elements["del[]"].checked);
		}
	}
}

jQuery.fn.resizeTextarea = function() {
	return this.bind("keyup change click focus drop", function() {
		$(this).height(function() {
			return this.scrollHeight;
		});
	}).trigger("keyup");
};

$(function() {
	$('.autoResizeTA').resizeTextarea();
});
