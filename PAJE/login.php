<html>
	<head>
		<title>LOGIN</title>
		<style>
			body{ background-color: rgb(40,40,55); }  
			form{background-color: rgb(130,130,130); width: 11%; padding: 5px; position:relative; left: 45%; top: 20em; } }
		</style>
	</head>
	<body>
	<?php session_start(); $_SESSION["Authorized"] = "FALSE" ?>
		<span>
		<form name="loginForm" method="POST" action="loginWork.php">
			<input type="text" name="username" value="Username" /><br />
			<input type="password" name="pass" /></br />
			<input type="submit" value="Submit" />
		</form>
		</span>
	</body>
</html>