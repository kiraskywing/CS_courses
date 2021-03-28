<div class="col-md-4">

    <?php 
        if (isset($_POST['submit'])) {
            $search = $_POST['search'];
            try {
                $stmt=$connection->prepare("SELECT * FROM posts WHERE post_tags LIKE :search");
                $stmt->execute(array('search' => '%' . $search . '%'));

                if ($stmt->rowCount()==0) {
                    echo "<h1> No result </h1>";
                }
                else {
                    echo "<h1> Has result </h1>";
                }
                
                // while ($row = $stmt->fetch()) {
                //     $cat_title = $row['cat_title'];
                //     echo "<li><a href='#'>{$cat_title}</a></li>";
                // }
            }
            catch(PDOException $e) {
                echo 'query failed: ' . $e->getMessage();
            }
        }
    ?>

    <!-- Blog Search Well -->
    <div class="well">
        <h4>Blog Search</h4>
        
        <form action="" method="post">
            <div class="input-group">
                <input name="search" type="text" class="form-control">
                <span class="input-group-btn">
                    <button name="submit" class="btn btn-default" type="submit">
                        <span class="glyphicon glyphicon-search"></span>
                    </button>
                </span>
            </div>
        </form>
        
        <!-- /.input-group -->
    </div>

    <!-- Blog Categories Well -->
    <div class="well">
        <h4>Blog Categories</h4>
        <div class="row">
            <div class="col-lg-6">
                <ul class="list-unstyled">
                    <li><a href="#">Category Name</a>
                    </li>
                    <li><a href="#">Category Name</a>
                    </li>
                    <li><a href="#">Category Name</a>
                    </li>
                    <li><a href="#">Category Name</a>
                    </li>
                </ul>
            </div>
            <!-- /.col-lg-6 -->
            <div class="col-lg-6">
                <ul class="list-unstyled">
                    <li><a href="#">Category Name</a>
                    </li>
                    <li><a href="#">Category Name</a>
                    </li>
                    <li><a href="#">Category Name</a>
                    </li>
                    <li><a href="#">Category Name</a>
                    </li>
                </ul>
            </div>
            <!-- /.col-lg-6 -->
        </div>
        <!-- /.row -->
    </div>

    <!-- Side Widget Well -->
    <div class="well">
        <h4>Side Widget Well</h4>
        <p>Lorem ipsum dolor sit amet, consectetur adipisicing elit. Inventore, perspiciatis adipisci accusamus laudantium odit aliquam repellat tempore quos aspernatur vero.</p>
    </div>

</div>