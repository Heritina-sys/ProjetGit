<?php
/**
 * Database connection — configuration template.
 *
 * Copy this file to `db.php` and fill in your own credentials.
 * `db.php` is listed in .gitignore and must never be committed.
 *
 *     cp db.example.php db.php
 *
 * Historical note: until September 2026 the four scripts in this repository
 * each opened their own PDO connection with the credentials written inline
 * (`root` / a one-character password). Those credentials were public in this
 * repository from 2024 onward and must be considered compromised — see
 * SECURITY.md.
 */

declare(strict_types=1);

$DB_HOST = getenv('DB_HOST') ?: 'localhost';
$DB_NAME = getenv('DB_NAME') ?: 'Message';
$DB_USER = getenv('DB_USER') ?: 'change_me';
$DB_PASS = getenv('DB_PASS') ?: 'change_me';

try {
    $bdd = new PDO(
        "mysql:host={$DB_HOST};dbname={$DB_NAME};charset=utf8mb4",
        $DB_USER,
        $DB_PASS,
        [
            PDO::ATTR_ERRMODE            => PDO::ERRMODE_EXCEPTION,
            PDO::ATTR_DEFAULT_FETCH_MODE => PDO::FETCH_ASSOC,
            PDO::ATTR_EMULATE_PREPARES   => false,
        ]
    );
} catch (PDOException $e) {
    // Do not echo $e->getMessage() in production: it leaks host and user names.
    error_log('Database connection failed: ' . $e->getMessage());
    http_response_code(500);
    die('Database connection failed.');
}
