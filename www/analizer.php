<?php
// autoxmlclass © 2013-2015 sea-kg (mrseakg@gmail.com)

class Element
{
	var $name;
	var $attr = array();
	var $elems = array();
	var $dep = array();
	var $body = false;

	function name() {
		return $this->name;
	}
	
	// ------------------------
	
	function setName($name) {
		$this->name = $name;
	}
	
	// ------------------------
		
	function classname() {
		return "_".$this->name;
	}

	// ------------------------
	
	function reset()
	{
		foreach($this->attr as $attrname => $attrval)
		{
			// $val = $this->attr[$attrname];
			if( $attrval == 1 || $attrval == 0)
			   $this->attr[$attrname] = 0;
			else
				$this->attr[$attrname] = 2;
		};
		
		
		foreach($this->elems as $elemname => $elemval)
		{
			if( $elemval == 0 || $elemval == 1)
				$this->elems[$elemname] = 0;
			else if($elemval > 1)
				$this->elems[$elemname] = 2;
		};
		/*foreach($this->attr as $attrname)
			$this->attr[$attrname] = 0;*/
	}
	
	// ------------------------
	
	function merge($elem)
	{
		foreach($elem->elems as $name => $val)
		{
			if(isset($this->elems[$name]))
			{
				$cur = $this->elems[$name];
				$this->elems[$name] = ($cur >= $val) ? $cur : $val;
			}
			else
				$this->elems[$name] = $val;
		};
		
		foreach($elem->attr as $name => $val)
		{
			if(isset($this->attr[$name]))
			{
				$cur = $this->attr[$name];
				$this->attr[$name] = ($cur >= $val) ? $cur : $val;
			}
			else
				$this->attr[$name] = $val;
		};
	}
	
	// ------------------------
	
	function addAttributeName($name) {
		if(isset($this->attr[$name]))
			$this->attr[$name] = $this->attr[$name] + 1;
		else
			$this->attr[$name] = 1;
	}
	
	// ------------------------
		
	function addSubElement($name) {

		if(isset($this->elems[$name]))
			$this->elems[$name] = $this->elems[$name] + 1;
		else
			$this->elems[$name] = 1;
	}
	
	// ------------------------
	
	function setBody($b) {
		$this->body = $b;
	}
};
	
////////////////////////////////

class Analizer {
	var $elements = Array();
	var $namespaces = Array();
	
	function printElements() {
		foreach($this->elements as $elemname => $elem) {
			echo "\r\n";
			echo "Element:\r\n";
			echo "\tName: '".$elem->name."'\r\n";
			echo "\tBody: '".($elem->body ? 'true' : 'false')."'\r\n";
			echo "\tAttributes:\r\n";
			foreach($elem->attr as $attrname => $attr) {
				echo "\t\t".$attrname.": ".$attr."\r\n";
			}
			echo "\tElements:\r\n";
			foreach($elem->elems as $childname => $childs) {
				echo "\t\t".$childname.": ".$childs."\r\n";
			}
			/*echo "\tDep:\r\n";
			foreach($elem->dep as $childname => $childs) {
				echo "\t\t".$childname.": ".$childs."\r\n";
			}*/
		}
	}
	
	function parse_string($data_xml) {
		$xml = simplexml_load_string($data_xml);
		$this->parse_xml($xml, true);
	}

	function parse_xml($xml, $root = false) {
		$obj = "";
		$xmlName = $xml->getName();
		// echo "[".$xmlName."]";
		if(isset($this->elements[$xmlName]))
		  $obj = $this->elements[$xmlName];
		else {
			$obj = new Element();
			$obj->setName($xmlName);
			$this->elements[$xmlName] = $obj;
		}

		$obj->reset();
		
		if($xml->children()->count() == 0) {
			$obj->setBody(true);
		}
		
		// $attrs = new Element();
		if($xml->attributes()->count() > 0) {
			foreach($xml->attributes() as $attrname => $attrvalue) {
				// todo
				$obj->addAttributeName($attrname);
				// echo "\t\tQString ".$attrname.";\n"; // ."; // default value = $attrvalue \n";
			}
		}

		foreach($xml->children() as $child)	{
			$obj->addSubElement($child->getName());
		}

		foreach($xml->children() as $child)
		{
			// $obj->addSubElement($child->getName());
			$this->parse_xml($child, false);
			// $elements = parse_xmlclass($child, false, $ident."\t");
		}
			
		
		foreach($this->namespaces as $name_ns => $url_ns )
		{
			foreach($xml->children($url_ns) as $child)
			{
				// $obj->addSubElement($child->getName());
				$this->parse_xml($child, false);
				// $elements = parse_xmlclass($child, false, $ident."\t");
			}
		}
		// echo $ident."} ";
		
		// $obj->reset();
		// $elements[$obj->name()]->reset();
		$this->elements[$obj->name()]->merge($obj);
	}
}
