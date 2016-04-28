<?php


$Username = $_POST["username"];
$Password = $_POST["pass"];


$db = mysqli_connect("localhost", "root", "", "PAJE");
if(!$db){
	die('Could not establish connection.');
}
$connection = $db;
			
$command = "SELECT * FROM `Users` WHERE `Username` = '" . $Username . "' && `Password` = '" . $Password . "' ";
$result = mysqli_query($connection, $command);



if(!$result){
	//header("Location: login.php");
	echo $connection->error;
}
else{
	$row = mysqli_fetch_assoc($result);
	if($row["Username"]){
		session_start();
		$_SESSION["Authorized"] = "TRUE";
		header("Location: mainMenu.html");
	}
	else{
		header("Location: login.php");
	}
}

$connection->close();
			
/*
if($_POST["username"] == "Connor"){

header("Location: mainMenu.html");
}
else{
	header("Location: login.php");
}
*/
?>