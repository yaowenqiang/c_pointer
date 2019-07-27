<?php
    function sort_strings($a)
    {
        $len = count($a);
        for($i=0;$i<$len;$i++) {
            //for($j=0;$j<$i;$j++) {
            for($j=$i+1;$j<$len;$j++) {
                if($a[$i] > $a[$j]) {
                    list($a[$j], $a[$i]) = array($a[$i], $a[$j]);
                } 
            }
        }
        return $a;
    }

$arr = array("hello","are","you", "ok", "i", "am" , "fine", "thank", "you");
print_r($arr);
$returnArr = sort_strings($arr);
print_r($returnArr);
sort($arr);
print_r($arr);
?>
