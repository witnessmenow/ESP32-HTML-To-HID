R"(
<!DOCTYPE html>
<html>
  <head>
    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0, maximum-scale=1.0, user-scalable=no" />
    <!-- CSS only -->
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css" crossorigin="anonymous">
  </head>
  <body>
    <div class="container-fluid" style="margin-top: 2em;">
      <div class="row justify-content-center">
        <div class="col-6">
          <button id="up" type="button" class="btn btn-primary" style="height: 100%; width: 100%" onclick='makeAjaxCall("command?press=1")'>Up</button>
        </div>
      </div>
      <div class="row justify-content-between" style="margin-top: 1em;">
        <div class="col-6">
          <button id="left" type="button" class="btn btn-primary" style="height: 100%; width: 100%" onclick='makeAjaxCall("command?press=2")'>Left</button>
        </div>
        <div class="col-6">
          <button id="right" type="button" class="btn btn-primary" style="height: 100%; width: 100%" onclick='makeAjaxCall("command?press=3")'>Right</button>
        </div>
      </div>
      <div class="row justify-content-center" style="margin-top: 1em;">
        <div class="col-6">
          <button id="down" type="button" class="btn btn-primary" style="height: 100%; width: 100%" onclick='makeAjaxCall("command?press=4")'>Down</button>
        </div>
      </div>
      <div class="row" style="margin-top: 2em;">
        <div class="col-3">
          <button id="esc" type="button" class="btn btn-primary" style="height: 100%; width: 100%" onclick='makeAjaxCall("command?press=5")'>Escape</button>
        </div>
        <div class="col-6">
          <button id="enter" type="button" class="btn btn-primary" style="height: 100%; width: 100%" onclick='makeAjaxCall("command?press=6")'>Enter</button>
        </div>
        <div class="col-3">
          <button id="exit" type="button" class="btn btn-primary" style="height: 100%; width: 100%" onclick='makeAjaxCall("command?press=7")'>Exit</button>
        </div>
      </div>
      <div class="row justify-content-center" style="margin-top: 2em;">
        <div class="col-6">
          <input id="inputText" type="text" placeholder="Type something…" style="height: 100%; width:100%">
        </div>
        <div class="col-3">
          <button id="send" type="button" class="btn btn-primary" style="height: 100%; width: 100%" onclick='sendText()'>Send</button>
        </div>
      </div>
    </div>
    <script>
      var sendTextCount = 0;

      function sendText() {
        var text = document.getElementById("inputText").value;
        sendTextCount++;
        // document.getElementById("sendTextCount").value = sendTextCount;
        makeAjaxCall("text?text=" + encodeURI(text));
      }

      function callAjax(url, callback) {
        var xmlhttp;
        // compatible with IE7+, Firefox, Chrome, Opera, Safari
        xmlhttp = new XMLHttpRequest();
        xmlhttp.onreadystatechange = function() {
          if (xmlhttp.readyState == 4 && xmlhttp.status == 200) {
            callback(xmlhttp.responseText);
          }
        };
        xmlhttp.open("GET", url, true);
        xmlhttp.send();
      }

      function makeAjaxCall(url) {
        callAjax(url, function() {});
      }
    </script>
  </body>
</html>



)"
