R"(
<!DOCTYPE html>
<html>
  <head>
    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0, maximum-scale=1.0, user-scalable=no" />
    <!-- CSS only -->
    <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.5.0/css/bootstrap.min.css" integrity="sha384-9aIt2nRpC12Uk9gS9baDl411NQApFmC26EwAOH8WgZl5MYYxFfc+NcPb1dKGj7Sk" crossorigin="anonymous">

    <!-- JS, Popper.js, and jQuery -->
    <script src="https://code.jquery.com/jquery-3.5.1.slim.min.js" integrity="sha384-DfXdz2htPH0lsSSs5nCTpuj/zy4C+OGpamoFVy38MVBnE+IbbVYUew+OrCXaRkfj" crossorigin="anonymous"></script>
    <script src="https://cdn.jsdelivr.net/npm/popper.js@1.16.0/dist/umd/popper.min.js" integrity="sha384-Q6E9RHvbIyZFJoft+2mJbHaEWldlvI9IOYy5n3zV9zzTtmI3UksdQRVvoxMfooAo" crossorigin="anonymous"></script>
    <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.5.0/js/bootstrap.min.js" integrity="sha384-OgVRvuATP1z7JjHLkuOU7Xw704+h835Lr+6QL9UvYjZE3Ipu6Tp75j7Bh/kR0JKI" crossorigin="anonymous"></script>
  </head>
  <body>
    <div class="container-fluid" style="margin-top: 2em;">
      <div class="row justify-content-center">
        <div class="col-6">
          <button id="up" type="button" class="btn btn-primary" style="height: 100%; width: 100%" onClick='makeAjaxCall("command?press=1")'>Up</button>
        </div>
      </div>
      <div class="row justify-content-between" style="margin-top: 1em;">
        <div class="col-6">
          <button id="left" type="button" class="btn btn-primary" style="height: 100%; width: 100%" onClick='makeAjaxCall("command?press=2")'>Left</button>
        </div>
        <div class="col-6">
          <button id="right" type="button" class="btn btn-primary" style="height: 100%; width: 100%" onClick='makeAjaxCall("command?press=3")'>Right</button>
        </div>
      </div>
      <div class="row justify-content-center" style="margin-top: 1em;">
        <div class="col-6">
          <button id="down" type="button" class="btn btn-primary" style="height: 100%; width: 100%" onClick='makeAjaxCall("command?press=4")'>Down</button>
        </div>
      </div>
      <div class="row" style="margin-top: 2em;">
        <div class="col-3">
          <button id="esc" type="button" class="btn btn-primary" style="height: 100%; width: 100%" onClick='makeAjaxCall("command?press=5")'>Escape</button>
        </div>
        <div class="col-6">
          <button id="enter" type="button" class="btn btn-primary" style="height: 100%; width: 100%" onClick='makeAjaxCall("command?press=6")'>Enter</button>
        </div>
        <div class="col-3">
          <button id="exit" type="button" class="btn btn-primary" style="height: 100%; width: 100%" onClick='makeAjaxCall("command?press=7")'>Exit</button>
        </div>
      </div>
      <div class="row justify-content-center" style="margin-top: 2em;">
        
        <div class="col-6">
          <input id="inputText" type="text" placeholder="Type something…" style="height: 100%; width:100%">
        </div>
        <div class="col-3">
          <button id="send" type="button" class="btn btn-primary" style="height: 100%; width: 100%" onClick='sendText()' > Send </button>
        </div>
      </div>
       <!-- 
       <div class="row justify-content-center" style="margin-top: 2em;">
        
        <div class="col-12">
          <input id="sendTextCount" type="text" placeholder="Type something…" style="height: 100%; width:100%">
        </div>
      </div>
       -->
    </div >
    <script>

        var sendTextCount = 0;

      function sendText() {
        var text = document.getElementById("inputText").value;
        sendTextCount++
        //document.getElementById("sendTextCount").value = sendTextCount;
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
        }
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
