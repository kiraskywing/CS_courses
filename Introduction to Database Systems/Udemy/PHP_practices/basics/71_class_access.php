<?php 

class Car {
    public $wheels = 4; // Can be used anywhere
    protected $hood = 1;// only available inside        class or sub-classes or methods
    private $engine = 1; // Only available inside the class
    
    var $doors = 3;    // the same as public
    
    function showProperty(){
        echo $this->wheels . " Public Wheels Inside Car Class <br> ";
        echo $this->hood . " Protected Hood Inside Car Class<br>";
        echo $this->engine . " Private Engine Inside Car Class<br>";
    }
}
class Semi extends Car {
    function showProperty(){
        echo $this->wheels . " Public Wheels inside the Semi Class<br>"; 
        echo $this->hood . " Protected Hood inside the Semi Class <br>";
        echo $this->engine;
    } 
}

$bmw = new Car();
$semi = new Semi();

echo $bmw->showProperty();
echo $semi->showProperty();
echo $bmw->doors . " Public Wheels Outside all the classes" ;
?>