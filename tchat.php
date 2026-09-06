<?php
    session_start();
    require_once __DIR__ . '/db.php';   // provides $bdd — see db.example.php
    $req = $bdd->prepare('INSERT INTO Chat(Nom,message,date_creation) VALUES(:nom,:message,NOW())');
  /// On exécute la requête pour lesquelle on ajoute des élements:
    $req->execute(array(
        'nom' => $_SESSION['nom'],
        'message' => $_POST['message'],
    ));
    header('Location: chat.php');
?>
