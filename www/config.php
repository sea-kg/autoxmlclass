<?php
	$config = Array();
	
	$config['langs'] = Array();
	
	$config['langs']['cpp_qt_useqxml'] = Array();
	$config['langs']['cpp_qt_useqxml']['name'] = 'C++ & Qt 5.1 (QXmlReader, QXmlWriter)';
	$config['langs']['cpp_qt_useqxml'][''] = 
	$config['langs']['cpp_qt_useqxml']['include_file'] = 'generators/cpp_qt_useqxml.php';
		
	$config['langs']['cpp_cbuilderxe3_usexml'] = Array();
	$config['langs']['cpp_cbuilderxe3_usexml']['name'] = 'C++ Builder XE3 & TXMLDocument';
	$config['langs']['cpp_cbuilderxe3_usexml']['include_file'] = 'generators/cpp_cbuilderxe3_usexml.php';
	
	$config['langs']['java_usexml'] = Array();
	$config['langs']['java_usexml']['name'] = 'Java (todo)';
	$config['langs']['java_usexml']['include_file'] = 'generators/java_usexml.php';
	
	$config['langs']['python_usexml'] = Array();
	$config['langs']['python_usexml']['name'] = 'Python (todo)';
	$config['langs']['python_usexml']['include_file'] = 'generators/python_usexml.php';
	
	$config['langs']['php_simplexml'] = Array();
	$config['langs']['php_simplexml']['name'] = 'PHP 5 (use simple xml)';
	$config['langs']['php_simplexml']['include_file'] = 'generators/php5_simplexml.php';
	
	$config['langs']['csharp_usexml'] = Array();
	$config['langs']['csharp_usexml']['name'] = 'C# (todo)';
	$config['langs']['csharp_usexml']['include_file'] = 'generators/csharp_usexml.php';
	

function copyright_cpp()
{
	return "
// autoxmlclass © 2013-2015 sea-kg (mrseakg@gmail.com)
// open source code: https://github.com/sea-kg/autoxmlclass/
// Attention:
//     This file was automaticly generate on http://".$_SERVER["SERVER_NAME"].$_SERVER["PHP_SELF"]."
// ".date("Y M d H:i")."
";
}
