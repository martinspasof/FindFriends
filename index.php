<?php 
define('ROOT', dirname($_SERVER['SCRIPT_FILENAME']));
$WEB_ROOT = "http://" . $_SERVER['HTTP_HOST'] . dirname($_SERVER['PHP_SELF']) . "/";
define('WEB_ROOT', $WEB_ROOT);

include ROOT . '/html/header.inc';
require_once("./AutoLoader.inc");
        
include ROOT . '/modules/Users/Controllers/UsersController.inc';

include ROOT . '/html/footer.inc';