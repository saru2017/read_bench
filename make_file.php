<?php


for($i = 0; $i < 10; $i++){
    $filename = sprintf("dummy_%04d.dat", $i);
    echo($filename);
    system("dd if=/dev/zero of=$filename bs=1000000 count=1");
}

?>
