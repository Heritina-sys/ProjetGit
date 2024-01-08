<!doctype html>
<html>
    <head>
        <meta charset="utf-8" />
        <title> Bonjour depuis PHP </title>
        <link rel="stylesheet" href="../StpM/cCompte.css">
    </head>
    <body>
        <div class="div1">
            <div class="div2"><img src="../StpM/utilisateur.png"></div>
            <br><br>
            <form action="test.php" method="post">
                <label>Nom d'utilisateur : </label>
                <input type="text" name="nom" class="input1" required>
                <br><br><br><br>
                <label>Mot de passe : </label>
                <input type="password" name="password" required>
                <br><br>
                <button type="submit">Suivant</button>
        </form>
    </body>
</html>

