		<?php
		
			$value = $_GET["val"];
			$type = $_GET["type"];
			
			//return $_GET["val"] . " is the value and " . $_GET["type"] . " is the type";
			
			$db = mysqli_connect("localhost", "root", "", "PAJE");
			if(!$db){
				die('Could not establish connection.');
			}
			$connection = $db;
			
			if($type == "Title"){
				$command = "SELECT * FROM journalentries WHERE Title LIKE '%" . $value . "%'";
			}

			else if($type == "Keyword"){
				$command = "SELECT * FROM journalentries WHERE Keyword LIKE '%" . $value . "%'";
			}
			else if($type == "Entry"){
				$command = "SELECT * FROM journalentries WHERE Entry LIKE '%" . $value . "%'";

			}
			else if($type == "Timestamp"){
				$command = "SELECT * FROM journalentries WHERE Timestamp LIKE '%" . $value . "%'";
			}
			
			else{
				$command = "SELECT * FROM journalentries";
			}
			
			$result = mysqli_query($connection, $command);
			if(!$result){
				die('Could not produce results from connected database');
			}
			echo "<table>";
			echo "<tr><td>Title</td><td>Entry</td><td>Timestamp</td><td>Author</td><td>Keyword</td></tr>";
			while($row = mysqli_fetch_assoc($result)){
				echo "<tr>";
				echo "<td>" . $row['Title'] . "</td>";
				echo "<td>" . $row['Entry'] . "</td>";
				echo "<td>" . $row['Timestamp'] . "</td>";
				echo "<td>" . $row['Author'] . "</td>";
				echo "<td>" . $row['Keyword'] . "</td>";
				echo "</tr>";
		
			}
			echo "</table>";
			$connection->close();
			
		?> 