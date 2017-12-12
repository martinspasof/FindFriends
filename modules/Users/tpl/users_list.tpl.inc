<link rel="stylesheet" href="<?= WEB_ROOT ?>/modules/Users/css/users_style.css"/>
<div class="container" id="find_new_friends">
    <h2>Find New Friends List</h2>
    <?php if (!empty($this->get('slice_get_users'))) { ?>
      <table id="users_list_table" class="table">
          <thead>      
              <tr>
                  <th>#</th>     
                  <th>Find Friend Names</th>
                  <th>Country</th>
                  <th>Language</th>
                  <th>Status</th>
              </tr>
          </thead>

          <tbody>      
              <?php
              $row = $this->get('paging')['row'];
              foreach ($this->get('slice_get_users') as $key => $data_friend) {
                ?>
                <tr id="<?= 'friend_' . $data_friend['user_id']; ?>">
                    <td><?= $row++; ?></td>
                    <td><?= $data_friend['friend_name']; ?></td>
                    <td><?= $data_friend['country_name']; ?></td>
                    <td><?= $data_friend['language_name']; ?></td>
                    <td><?= $data_friend['status']; ?></td>
                </tr>
        <?php } ?>            
          </tbody>
      </table>

      <div class="pagination">
          <?php
          for ($i = 0; $i < $this->get('paging')['max_pages']; $i++) {
            $css_class_active = "";
            if ($i == ($this->get('paging')['page'] - 1)) {
              $css_class_active = "class='active'";
            }
            ?>
              <a <?= $css_class_active ?> href="#" onclick="get_page('<?= ($i + 1) ?>')"><?= ($i + 1) ?></a>
       <?php }
       
        }else { ?>
         <div class="alert alert-danger">
              <strong>No Records!</strong>.
          </div>   
        <?php } ?>
    </div> 
</div>


