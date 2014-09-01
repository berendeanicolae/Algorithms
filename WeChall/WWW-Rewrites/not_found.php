<?php
//http://httpd.apache.org/docs/current/custom-error.html
//http://stackoverflow.com/questions/12760351/getting-404-not-found-error-while-trying-to-use-errordocument

$filename = basename("$_SERVER[HTTP_HOST]$_SERVER[REQUEST_URI]");
$withoutExt = preg_replace('/\.[^.]+$/','', $filename);
$vals = explode("_mul_", $withoutExt);
$rez = bcmul($vals[0], $vals[1]);
print $rez;