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
    $req = $bdd->prepare('INSERT INTO Chat(Nom,message,date_creation) VALUES(:nom,:message,NOW())');
  /// On exécute la requête pour lesquelle on ajoute des élements:
    $req->execute(array(
        'nom' => $_SESSION['nom'],
        'message' => $_POST['message'],
    ));
    header('Location: chat.php');
?>
