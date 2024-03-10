<body>
<?php
$host = '172.20.10.2';                                                
$user = 'kokonum';           
$passwd = 'ilovevul3a94lkk';         
$database = 'kokonum';       
$connect = new mysqli($host , $user , $passwd , $database);   

if ($connect->connect_error){                 
    die("連線失敗:".$connect->connect_error);           
}
else{
    $connect->query("SET NAMES 'UTF8'");                
    $C = $_GET["c"];                                        
    $Insertsql = "INSERT INTO dht (`Sound`) VALUES ('$C')"; 
    $status = $connect->query($Insertsql);         
    print($status);                                     
    $selectSql = "SELECT * FROM dht ";                  
    $memberData = $connect->query($selectSql);          
    if ($memberData->num_rows>0){                   
        while ($row = $memberData->fetch_assoc()){  
            print_r($row);
            // print_r($row['Time']);
            print_r($row['Sound']);
            echo '<br>';
        }
    }else {
        echo '無資料';
    }
    }
?>
</body>