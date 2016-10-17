<div class="sports-page siderbar-sport">
    <?php foreach ($rows as $index => $row) {
        ?>
        <span class="widget-title"><?php echo $row['title']; ?></span>
        <?php echo $row['body']; ?>
    <?php }; ?>
</div>