<?php
    session_start();
    $_SESSION['nom'] = $_POST['nom'];
  /// On se connecte à la base de données:
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
            break;
        }
    }
    if($test){
        header('Location: verification_nom.php');
    }
    else{
    $req = $bdd->prepare('INSERT INTO Compte(Nom,Password,date_creation) VALUES(:nom,:password,NOW())');
  /// On exécute la requête pour lesquelle on ajoute des élements:
    $req->execute(array(
        'nom' => $_POST['nom'],
        'password' => $_POST['password'],
    ));
    header('Location: chat.php');
    }
?>
