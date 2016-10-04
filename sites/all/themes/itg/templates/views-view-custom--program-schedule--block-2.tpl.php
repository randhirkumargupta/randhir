
    <?php foreach ($rows as $index => $row): ?>
<ul class="profile-detail">
    <li>Speaker: </li>
    <li class="image"><?php print $row['field_story_extra_large_image']; ?></li>
        <li>
            <span class="title"><?php print $row['title']; ?></span>
            <span class="designation"><?php print $row['field_story_new_title']; ?></span>
        </li>
        </ul>
    <?php endforeach; ?>
