PAJE is a very basic PHP/Database combination that allows users to write "journal" entries and search through them
at a later date. As a PHP program, it must be run in a php-compatable environment, such as a web server or locally
through Wampserver. This document will assume the latter. 

When stored within Wampserver's www folder and with Wampserver active, a user may login to the code through 
localhost/PAJE/login.php. Login may be achieved through adding users to the user's table in PAJE.sqlite. Alternatively,
use one of the following sample logins:

Username: Connor
Password: aura

Username Faisal
Password: javascript


Once inside, the main menu will lead to a creation page which will submit new values to 
the database, which can be read on the view page through the main menu.