<?php

$file = "example.txt";

if ($handle = fopen($file, 'r')) {
    $content = fread($handle, filesize($file));
    echo $content;
    fclose($handle);
}
else {
    echo "Not able to write on the file";
}

?>