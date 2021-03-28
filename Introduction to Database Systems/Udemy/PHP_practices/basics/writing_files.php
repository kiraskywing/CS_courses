<?php

$file = "example.txt";

if ($handle = fopen($file, 'w')) {
    fwrite($handle, 'Hello world<br>This is a test<br>I love programming');
    fclose($handle);
}
else {
    echo "Not able to write on the file";
}

?>