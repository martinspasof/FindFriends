<?php

namespace modules\Users\Classes;
use resource\Db;

class User {


  public function getNewFriends() {
    $user_id = isset($_POST['user_id']) ? $_POST['user_id'] : 1;
    $country_id = isset($_POST['country_id']) ? $_POST['country_id'] : '';

    $_SESSION['user_id'] = isset($_POST['user_id']) ? $_POST['user_id'] : $_SESSION['user_id'];
    $_SESSION['country_id'] = isset($_POST['country_id']) ? $_POST['country_id'] : $_SESSION['country_id'];

    $sess_user_id = $_SESSION['user_id'];
    $sess_country_id = $_SESSION['country_id'];

    $sql_get_data_new_friends ="SELECT usr.user_id,usr.real_name as friend_name,usr.email,lng.country_name,lng.language_name,fr.status 
                                   FROM `friends` fr 
                                JOIN users us 
                                LEFT JOIN `users` usr
                                ON usr.user_id=fr.fr2 
                                JOIN lang_table lng
                                ON lng.language_id = '$sess_country_id' AND usr.country=lng.language_id
                                WHERE (fr.fr2 != $sess_user_id OR fr.fr1 != $sess_user_id)  
                                AND us.user_id=fr.fr1
                                GROUP BY usr.email
                                  UNION ALL
                                SELECT usr.user_id,usr.real_name as friend_name,usr.email,lng.country_name,lng.language_name,fr.status FROM `friends` fr 
                                JOIN users us 
                                LEFT JOIN `users` usr
                                ON usr.user_id=fr.fr1 
                                JOIN lang_table lng
                                ON lng.language_id = '$sess_country_id' AND usr.country=lng.language_id
                                WHERE (fr.fr2 != $sess_user_id OR fr.fr1 != $sess_user_id)
                                AND us.user_id=fr.fr2 
                                GROUP BY usr.email;";

               $db = new Db();
               $data_new_friends = $db->select($sql_get_data_new_friends);

               return $data_new_friends;
  }

  public function getUserCountries() {
     $sql_user_countries = "SELECT * FROM `lang_table`";

     $database = new Db();
     $get_user_countries = $database->select($sql_user_countries);

     return $get_user_countries;

  }


}
