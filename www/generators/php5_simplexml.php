<?php

include_once("copyright.php");

class CodeGenerator {
	var $files = Array();
	function generate($elements) {
		$this->files = Array();
		$php_code = "<?php ";
		$php_code .= getCopyright()."\r\n";

		$elements = array_reverse($elements);

		foreach($elements as $elemname => $elem) {
			$php_code .= "class ".$elem->name." {\r\n";
			
			// variables (attr)
			foreach($elem->attr as $attrname => $count) {
				$varname = "s".ucfirst($attrname);
				$php_code .= "\tvar \$$varname;\r\n";
			}
			
			// variables (elem)
			foreach($elem->elems as $childelemname => $childelemval) {
				if ($childelemval > 1) {
					$varname = "arr".ucfirst($childelemname);
					$php_code .= "\tvar \$$varname = Array();\r\n";
				} else {
					$varname = "p".ucfirst($childelemname);
					$php_code .= "\tvar \$$varname = new $childelemname();\r\n";
				}
			}
			
			// setters and getters
			foreach($elem->attr as $attrname => $count) {
				$php_code .= "\r\n";
				$varname = "s".ucfirst($attrname);
				$php_code .= "\tfunction set".ucfirst($attrname)."(\$newval) {\r\n\t\t\$this->$varname = \$newval;\r\n\t};\r\n";
				$php_code .= "\r\n";
				$php_code .= "\tfunction get".ucfirst($attrname)."() {\r\n\t\treturn \$$varname;\r\n\t};\r\n";
			}

			$php_code .= "}\r\n\r\n";
		}

		$this->files['autoxmlclass.php'] = $php_code;
	}
};
