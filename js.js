function RecLink(link, category, action) {
	try {
		pageTracker._trackEvent(category, action);
		setTimeout('document.location = "' + link.href + '"', 100)
	} catch(err) {}
}

function ver_MouseOverTR(tr) {
	tr.style.backgroundColor='#464A6B';
}

function ver_MouseOutTR(tr) {
	tr.style.backgroundColor='';
}
