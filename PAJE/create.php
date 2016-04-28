<html>
	<head>
		<title>PAJE Creator</title>
		<style>
			body{ background-color: rgb(40,40,55); }
			form{ background-color: rgb(150,150,150); width: 15%; position: relative; padding: 5px; border-radius: 10px;}
			#fullDetail{ height: 150px; } 
		</style>
	</head>
	<body>
			<?php session_start(); if(!$_SESSION["Authorized"]){ header("Location: login.php"); } else if($_SESSION["Authorized"] == "FALSE") { header("Location: login.php"); }?>

	
		<form id="createPageForm" name="createPageForm" method="POST" action="createPageWork.php">
			Title: <input name="title" type="text" /><br />
			Time: <input disabled type="datetime" name="journalTime" value="<?php echo date("l jS F Y h:i:s A") ?>"/><br />
			Text: <textarea id="fullDetail" name="journalEntry" form="createPageForm"></textarea><br />
			Author: <input type="text" name="author" /><br />
			Keyword: <input type="text" name="keyword" /><br />
			<input type="submit" style="margin-top:15px;" value="Create New Entry"></input>
			<br />
			<a href="mainMenu.html">Main Menu</a>
			
		</form>
	</body>
</html>