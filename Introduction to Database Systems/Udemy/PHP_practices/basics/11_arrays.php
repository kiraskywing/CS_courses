<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Document</title>
</head>
<body>
<?php 

$numberList = array(267,8765,345,'5345', 345, '<h1>Hello</h1>');

//print_r($numberList);
print_r($numberList) . "<br>";
echo $numberList[0] . "<br>";
echo $numberList[1] . "<br>";
echo $numberList[2] . "<br>";
echo $numberList[3] . "<br>";
echo $numberList[4] . "<br>";
echo $numberList[5] . "<br>";
    
?>

</body>
</html>