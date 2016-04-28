<html>
	<head>
		<title>PAJE Reader</title>
		<style>
			body{ background-color: rgb(40,40,55); }
			div{ background-color: rgb(150,150,150); width: 23%; position: relative; padding:5px; border-radius: 10px; }
			#results { width: 50%; }
			td{ border: solid black 1px; }
		</style>
		<script>
			function pageFinder(seek, type) {
			if (seek.length == 0) {
				document.getElementById("output").innerHTML = "";
			return;
			} 
			else {
				var xmlhttp = new XMLHttpRequest();
				
				xmlhttp.onreadystatechange = function() {
					if (xmlhttp.readyState == 4 && xmlhttp.status == 200) {
						document.getElementById("output").innerHTML = xmlhttp.responseText;
					}
			};
			var params = "val=" + seek + "&type=" + type;
			xmlhttp.open("GET", "viewPageWork.php?val=" + seek + "&type=" + type, true);
			xmlhttp.send();
    }
}		
			function findByTitle(t){
				pageFinder(t, "Title");
			}
			function findByDate(d){
				pageFinder(d, "Date");
			}
			function findByEntry(e){
				pageFinder(e, "Entry");
			}
			function findByKeyword(k){
				pageFinder(k, "Keyword");
			}
		</script>
		
	</head>
	<body>
		<!--
		<div id="divOutput">
			Title: <input id="titleOutput" style="margin-left: 40%;" type="text" disabled /><br />	
			Timestamp: <input type="text" style="margin-left: 29%;" id="timestampOutput" disabled /><br />
			Entry: <textarea id="entryOutput" style="margin-left: 33.5%;" disabled ></textarea><br />
			</div>
		-->
		<?php session_start(); if(!$_SESSION["Authorized"]){ header("Location: login.php"); } else if($_SESSION["Authorized"] == "FALSE") { header("Location: login.php"); }?>

		<hr />
		<div id="find">
			Find by Title: <input type="text" id="findTitle" /><button onclick="findByTitle(document.getElementById('findTitle').value)" >Seek</button><br />
			Find by Date: <input type="text" id="findDate" /><button onclick="findByDate(document.getElementById('findDate').value)">Seek</button><br />
			Find by Entry: <input type="text" id="findEntry" /><button onclick="findByEntry(document.getElementById('findEntry').value)">Seek</button><br />
			Find by Keyword: <input type="text" id="findKeyword" /><button onclick="findByKeyword(document.getElementById('findKeyword').value)">Seek</button><br />
			<a href="mainMenu.html">Main Menu</a>
		</div>
		<hr />
		<div id="results">
			Search Results: <br />
			<p id="output"></p>
		</div>
	</body>
</html>