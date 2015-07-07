<?php
	include_once('config.php');
	include_once('analizer.php');
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
	<form action="example.php" method="get">
	<table>
		<tr>
			<td>Select language:</td>
			<td><select name="output_lang">
				<?php
					foreach ($config['langs'] as $key => $value) {
						echo '<option value="'.$key.'">'.$value['name'].'</option>';
					}
				?>
				</select>
			</td>
			<tr>
				<td>Namespace: </td>
				<td><input name="namespace" type="text" value="example"/></td>
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
	$analizer->printElements();
?>
</pre>

</body>
</html>
