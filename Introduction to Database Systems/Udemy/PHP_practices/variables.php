<?php
$x = 5; // global scope

function myTest() {
  // using x inside this function will generate an error
  echo "<p>Variable x inside function is: $x</p>";
}
myTest();
echo "<p>Variable x outside function is: $x</p>";
?>

<?php
function myTest2() {
  $x2 = 5; // local scope
  echo "<p>Variable x2 inside function is: $x2</p>";
}
myTest2();
// using x outside the function will generate an error
echo "<p>Variable x2 outside function is: $x2</p>";
?>

<?php
$a = 5;
$b = 10;

function myTest3() {
  global $a, $b;
  $b = $a + $b;
}
myTest3();
echo $b . "<br>"; // outputs 15
?>

<?php
$x = 5;
$y = 10;

function myTest4() {
  $GLOBALS['y'] = $GLOBALS['x'] + $GLOBALS['y'];    // global variables in array
}
myTest4();
echo $y . "<br>"; // outputs 15
?>

<?php
function myTest5() {
  static $x = 0;
  echo "static value = " . $x . "<br>";
  $x++;
}

myTest5();
myTest5();
myTest5();
?>