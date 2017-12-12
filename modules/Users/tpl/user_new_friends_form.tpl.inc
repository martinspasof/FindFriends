<div style="margin: 20px;">
  <form method="post">
    Countries:<br>
    <select name="country_id" id="country_id">
      <?php
      if(is_array($this->get('get_user_countries'))) {
        foreach ($this->get('get_user_countries') as $country) {
          $selected = isset($_POST['country_id']) && ($country['language_id']==$_POST['country_id']) ? 'selected' : '';
          ?>
          <option <?=$selected?> value="<?= $country['language_id'] ?>"><?= $country['country_name'] ?></option>
        <?php }
      }
      ?>
    </select>
    <input type="hidden" id="user_id" name="user_id" value="1">
    <br><br>
    <input type="submit" name="find_friends" value="Find Friends">
  </form>
</div>
<br/>

<script>
    function get_page(page_id) {
        var country_id = $('#country_id').val();
        var user_id = $('#user_id').val();

        $.ajax({
            url: "index.php",
            type: "get",
            data: {action: 'get_page_id', page: page_id},
            success: function (response) {

                $('body').html(response);
                $('#country_id').val(country_id);
                $('#user_id').val(user_id);

            },
            error: function (jqXHR, textStatus, errorThrown) {
                console.log(textStatus, errorThrown);
            }


        });
    }

</script>