<?php
// autoxmlclass © 2013-2015 sea-kg (mrseakg@gmail.com)

class Element
{
	var $name;
	var $attr = array();
	var $elems = array();
	var $dep = array();
	var $body = false;
	
	function setName($name) {
		$this->name = $name;
	}

	function name() {
		return $this->name;
	}
};
	
class Analizer {
	var $elements = array();
	function parse($pathToXML) {
		
	}
}
