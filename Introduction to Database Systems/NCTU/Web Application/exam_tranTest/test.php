<?php

$dbservername='localhost';
$dbname='NCTU_examdb';
$dbusername='root';
$dbpassword='';

try
{
    $conn = new PDO("mysql:host=$dbservername;dbname=$dbname", $dbusername, $dbpassword);
    # set the PDO error mode to exception
    $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    $conn->beginTransaction();  
    $stmt=$conn->prepare("insert into accounts (AccountName, Amount) values ('Alice', 100)");
    $stmt->execute();
    $stmt=$conn->prepare("insert into accounts (AccountName, Amount) values ('Bob', 345)");
    $stmt->execute();
    $conn->commit();
    
    echo <<<EOT
        <!DOCTYPE html>
        <html>
            <body>
                <script>
                    alert("$msg");
                    window.location.replace("index.php");
                </script>
            </body>
        </html>
    EOT;
}
catch(Exception $e)
{
    if ($conn->inTransaction())
        $conn->rollBack();
    
        $msg=$e->getMessage();
    
    echo <<<EOT
        <!DOCTYPE html>
        <html>
            <body>
                <script>
                    alert("$msg");
                    window.location.replace("index.php");
                </script>
            </body>
        </html>
    EOT;
}
?>
