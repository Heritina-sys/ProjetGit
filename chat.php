<?php
        session_start();
        try
        {
            $bdd = new PDO('mysql:host=localhost;dbname=Message', 'root', 'h');
        }
        catch(Exception $e)
        {
            die('Erreur : '.$e->getMessage());
        }
        $reponse = $bdd->query('SELECT * FROM Chat ORDER BY ID DESC LIMIT 0, 10');
?>
<!doctype html>
<html>
    <head>
        <meta charset="utf-8" />
        <title> Bonjour depuis PHP </title>
        <link rel="stylesheet" href="../StpM/SChat.css">
    </head>
    <body>
        <div class="div1">
            <form action="tchat.php" method="post">
                <?php
                    while($donne = $reponse->fetch()){
                    echo "<p class=\"p1\">"; echo $donne['Nom'].  ' : '. $donne['message']; echo "</p>";
                    }
                ?>
         </div>
                <?php echo $_SESSION['nom'] ?> : <input type="text" name="message">
                <br>
                <button type="submit">Envoyer</button>
            </form>
            <a href="sCompte.php">Changer de compte</a>
            <a href="index.php">Revenir à l'acueil</a>
    </body>
</html>
