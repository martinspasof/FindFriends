<?php

  $users = new modules\Users\Classes\User();


  $get_user_countries = $users->getUserCountries();
  $user_new_friends_form = new modules\BaseModuleTemplater\Classes\BaseModuleTemplater(ROOT . '/modules/Users/tpl/user_new_friends_form.tpl.inc');
  $user_new_friends_form->set('get_user_countries', $get_user_countries);
  $user_new_friends_form->publish();

if(isset($_POST['find_friends']) || isset($_GET['page'])) {
  $get_new_friends = $users->getNewFriends();
  $stack = [];
  $stack['max_count'] = count($get_new_friends);
  $stack['limit'] = 25;
  $utils = new modules\Utils\Classes\Utils();
  $paging = $utils->pagination($stack);
  $slice_get_users = array_slice($get_new_friends, $paging['start'], $paging['limit']);

  $find_friends_list = new modules\BaseModuleTemplater\Classes\BaseModuleTemplater(ROOT . '/modules/Users/tpl/users_list.tpl.inc');
  $find_friends_list->set('slice_get_users', $slice_get_users);
  $find_friends_list->set('paging', $paging);
  $find_friends_list->publish();
}

