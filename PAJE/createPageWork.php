<?php 

$title = $_POST["title"];
$entry = $_POST["journalEntry"];
if($_POST["keyword"]){
	$keyword = $_POST["keyword"];
}
$author = $_POST["author"];

$db = mysqli_connect("localhost", "root", "", "PAJE");
if(!$db){
	die('Could not establish connection.');
}
$connection = $db;
			
$command = "INSERT INTO `journalentries`(`Id`,`Title`, `Entry`, `Timestamp`, `Author`, `Keyword`) VALUES (DEFAULT, '" . $title . "', '" . $entry . "', DEFAULT, '" . $author . "', '" . $keyword . "');";
$result = mysqli_query($connection, $command);
if(!$result){
	echo $connection->error;
	die('Could not produce results from connected database');
}

$connection->close();
			
header("Location: create.php");

?>