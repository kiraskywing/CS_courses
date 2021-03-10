<?php
$x = 5985;
var_dump($x);
var_dump(is_int($x));
var_dump(is_float($x));

$y = 10.365;
var_dump($y);
var_dump(is_int($y));
var_dump(is_float($y));

$z = 1.9e411;
var_dump($z);

$a = acos(8);
var_dump($a);    // NaN means "Not a number"

$cars = array("Volvo", "BMW", "Toyota");
var_dump($cars);

$x = "Hello world!";
$x = null;
var_dump($x);

echo "<br>PHP Numerical Strings<br>";
$x = 5985;
print "<br>5985 is numeric: ";
var_dump(is_numeric($x));

$x = "5985";
print "<br> \"5985\" is numeric: ";
var_dump(is_numeric($x));

$x = "59.85" + 100;
print "<br> \"5985\" + 100 is numeric: ";
var_dump(is_numeric($x));

$x = "Hello";
print "<br> \"Hello\" is numeric: ";
var_dump(is_numeric($x));

// Cast float to int
$x = 23465.768;
$int_cast = (int)$x;
echo "<br>" . $int_cast;
// Cast string to int
$x = "23465.768";
$int_cast = (int)$x;
echo "<br>" . $int_cast;

echo "<br>" . pi(); // returns 3.1415926535898
echo "<br>" . min(0, 150, 30, 20, -8, -200);  // returns -200
echo "<br>" . max(0, 150, 30, 20, -8, -200);  // returns 150
echo "<br>" . (sqrt(64));  // returns 8
echo "<br>" .(round(0.60));  // returns 1
echo "<br>" .(round(0.49));  // returns 0

echo "<br>" . strlen("Hello world!"); // outputs 12
echo "<br>" . str_word_count("Hello world!"); // outputs 2
echo "<br>" . strrev("Hello world!"); // outputs !dlrow olleH
echo "<br>" . strpos("Hello world!", "world"); // outputs 6
echo "<br>" . strpos("Hello world!", "ans"); // outputs false: 0
echo "<br>" . str_replace("world", "Dolly", "Hello world!"); // outputs Hello Dolly!

class Car {
    public $color;
    public $model;
    public function __construct($color, $model) {
      $this->color = $color;
      $this->model = $model;
    }
    public function message() {
      return "My car is a " . $this->color . " " . $this->model . "!" . "<br>";
    }
}
  
$myCar = new Car("black", "Volvo");
echo "<br>" . $myCar -> message();
$myCar = new Car("red", "Toyota");
echo $myCar -> message();
?>