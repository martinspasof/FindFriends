<?php
/**
 * Created by PhpStorm.
 * User: Martin
 * Date: 11.12.2017 г.
 * Time: 15:43 ч.
 */

namespace resource;


class Db {

  // The database connection
  protected $connection;

  protected static $result;

  /**
   * Connect to database
   *
   * @return bool false on failure / mysqli MySqli object instance on success
   */
  public function connect() {
    //try and connect to the database
    if (!isset($this->connection)) {
      // Load configuration as an array. Use the actual location of your configuration file
      $config = parse_ini_file('./configuration/config.ini');
      $this->connection = new \MySQLi($config['servername'], $config['username'], $config['password'], $config['dbname']);
      // If connection was not successful, handle the error
      if ($this->connection === FALSE) {
        // Handle error - notify administrator, log to a file, show an error screen, etc.
        return FALSE;
      }

      /* change character set to utf8 */
      if (!$this->connection->set_charset("utf8")) {
        printf("Error loading character set utf8: %s\n", $this->connection->error);
        exit();
      }

      return $this->connection;

    }
  }

  /**
   * Query the database
   *
   * @param $query The query string
   *
   * @return mixed The result of the mysqli::query() function
   */
  public function query($query) {
    // Connect to the database
    $connection = $this->connect();
    // Query the database
    $result = $connection->query($query);
    return $result;
  }

  /**
   * Quote and escape value for use in a database query
   *
   * @param string $value The value to be quoted and escaped
   * @return string The quoted and escaped string
   */
  public function escape($value) {
    $connection = $this->connect();
    return $connection->real_escape_string($value);
  }

  /**
   * Fetch rows from the database (SELECT query)
   *
   * @param $query The query string
   * @return bool False on failure / array Database rows on success
   */
  public function select($query) {
    $rows = array();
    $result = $this->query($query);
    if ($result === false) {
      return false;
    }
    while ($row = $result->fetch_assoc()) {
      $rows[] = $row;
    }
    return $rows;
  }

}