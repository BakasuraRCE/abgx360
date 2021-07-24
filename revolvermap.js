function rmt_ki101(m, s, i, c) {
    var l = encodeURIComponent(document.URL);
    var x = new Image();
    x.src = "http://ja.revolvermaps.com/c.html?i=" + i;
    x.onload = function() {
        this.width = 1;
    };
    var y = new Image();
    y.src = "http://ja.revolvermaps.com/r.html?i=" + i + "&l=" + l + "&r=" + new Date().getTime();
    y.onload = function() {
        this.width = 1;
    };
    var f = 'width="' + s + '"height="' + s + '"><param name="movie"value="http://ra.revolvermaps.com/f/t.swf"><param name="allowNetworking"value="all"><param name="allowScriptAccess"value="always"><param name="wmode"value="transparent"><param name="flashvars"value="m=' + m + '&i=' + i + '&c=' + c + '&s=' + s + '&l=' + l + '"><\/object>';
    if (navigator.plugins && navigator.plugins['Shockwave Flash'] && parseInt(navigator.plugins['Shockwave Flash'].description.replace(/\D+/, '')) > 8) document.write('<object data="http://ra.revolvermaps.com/f/t.swf"type="application/x-shockwave-flash"' + f);
    else {
        try {
            new ActiveXObject("ShockwaveFlash.ShockwaveFlash.9");
            document.write('<object classid="clsid:d27cdb6e-ae6d-11cf-96b8-444553540000"' + f);
        } catch (e) {
            document.write(s > 99 ? '<iframe style="margin-top:' + Math.ceil(s / 4) + 'px;margin-bottom:' + (s >> 2) + 'px;"width="' + s + '"height="' + (s >> 1) + '"scrolling="no"frameborder="0"marginwidth="0"marginheight="0"src="http://ra.revolvermaps.com/5/f.html?m=' + m + '&h=' + (s >> 1) + '&i=' + i + '&c=' + c + '&l=' + l + '"><\/iframe>' : '<a href="http://www.revolvermaps.com/?target=enlarge&i=' + i + '&color=' + c + '&m=' + m + '&ref=' + l + '"target="_top"><img src="http://ra.revolvermaps.com/d/v.png"width="70"height="70"alt="Map"style="border:0px;margin:' + ((s >> 1) - 35) + 'px;"><\/a>');
        }
    }
}