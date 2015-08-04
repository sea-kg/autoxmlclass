<?php
	include_once('config.php');
	include_once('analizer.php');	
		
	if (isset($_POST['namespace']) && isset($_POST['output_lang']) && isset($_FILES['input_xml'])) {
		$namespace = $_POST['namespace'];
		$lang = $_POST['output_lang'];
		$filename = $_FILES['input_xml']['tmp_name'];
		$analizer = new Analizer();
		
		if(file_exists($filename)) {
			$myfile = fopen($filename, "r") or die("Unable to open file!");
			$xml = fread($myfile,filesize($filename));
			// echo htmlspecialchars($xml);
			fclose($myfile);
			$analizer->parse_string($xml);
		} else {
			echo "Could not load file";
			exit;
		}

		include_once($config['langs'][$lang]['include_file']);
		$cg = new CodeGenerator();
		$cg->generate($analizer->elements, $namespace);


		$zipname = tempnam("/tmp", "autoxmlclass");
		$zip = new ZipArchive();
		if($zip->open($zipname, true ? ZIPARCHIVE::OVERWRITE : ZIPARCHIVE::CREATE) !== true) {
			echo "Could not create zip-archive ".$zipname;
			exit;
		}
		
		foreach($cg->files as $filename => $content) {
			// echo '<h1>'.$filename.'</h1>';
			// echo htmlspecialchars($content);
			$zip->addFromString($filename, $content);
		}
		$zip->close();
				
		header($_SERVER["SERVER_PROTOCOL"] . " 200 OK");
		header("Cache-Control: public"); // needed for i.e.
		header("Content-Type: application/zip");
		header("Content-Transfer-Encoding: Binary");
		header("Content-Length:".filesize($zipname));
		header("Content-Disposition: attachment; filename=".$namespace.'.zip');
		readfile($zipname); 
		unlink($zipname);
		exit;
	}
?><html>
<head>
<title>Example Generator classes & reader/writer for xml </title>
<meta http-equiv="Content-Type" content="text/html; charset=utf8">
</head>
<body onload="init_v();">
<hr>
<center>
	<h1>Example Generator xml-reader & xml writer</h1>
<hr>
	<form action="?" method="post" enctype="multipart/form-data">
	<table>
		<tr>
			<td>Select language:</td>
			<td><select name="output_lang">
				<?php
					$lang = isset($_GET['output_lang']) ? $_GET['output_lang'] : '';
					foreach ($config['langs'] as $key => $value) {
						echo '<option value="'.$key.'" '.($lang == $key ? 'selected="true"' : '').'>'.$value['name'].'</option>'."\r\n";
					}
				?>
				</select>
			</td>
			<tr>
				<td>Namespace: </td>
				<td><input name="namespace" type="text" value="example"/></td>
			</tr>
			<tr>
				<td>XML-file: </td>
				<td><input name="input_xml" type="file"/></td>
			</tr>
			<tr>
				<td></td>
				<td><input type="submit" value="OK"/></td>
			</tr>
		</tr>
	</table>
</center>
<center><h1>example.xml</h1></center>

<pre>
<?php
	$myfile = fopen("example.xml", "r") or die("Unable to open file!");
	$xml = fread($myfile,filesize("example.xml"));
	echo htmlspecialchars($xml);
	fclose($myfile);
	$analizer = new Analizer();
	$analizer->parse_string($xml);
	// Analizer
?>
</pre>

<center><h1>analizer-report.txt</h1></center>
<pre>
<?php
	echo $analizer->getElements();
	$namespace = isset($_GET['namespace']) ? $_GET['namespace'] : 'example';
	$lang = isset($_GET['output_lang']) ? $_GET['output_lang'] : 'cpp_qt_useqxml';
	
?>
</pre>

<center><h1>Source code for <?php echo $config['langs'][$lang]['name']; ?> </h1></center>
<pre>
<?php
	include_once($config['langs'][$lang]['include_file']);
	$cg = new CodeGenerator();
	$cg->generate($analizer->elements, $namespace);

	foreach($cg->files as $filename => $content) {
		echo '<h1>'.$filename.'</h1>';
		echo htmlspecialchars($content);
	}
	
?>
</pre>

</body>
</html>

