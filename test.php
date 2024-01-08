<?php
    session_start();
    $_SESSION['nom'] = $_POST['nom'];
    try
    {
        $bdd = new PDO('mysql:host=localhost;dbname=Message', 'root', 'h');
    }
    catch(Exception $e)
    {
        die('Erreur : '.$e->getMessage());
    }
    $reponse = $bdd->query('SELECT * FROM Compte');
    $test = false;
    ///testons si le nom existe ou pas
    while($donnees = $reponse->fetch()){
        if($_POST['nom'] == $donnees['Nom']){
            $test = true;
        }
    }
    if($test){
    /// A la recherche du champs ou est placer le nom
        $req = $bdd->prepare('SELECT * FROM Compte WHERE Nom = :Nom');
        $req->execute(array(
            'Nom' => $_POST['nom'],
        ));
        $pass = $req->fetch();
    ///une petite verification de mot de passe
        if($_POST['password'] == $pass['Password']){
            header('Location: chat.php');
        }
        else{
            header('Location: security.php');
        }
    }
    else{
        header('Location: retest.php');
    }
?>
