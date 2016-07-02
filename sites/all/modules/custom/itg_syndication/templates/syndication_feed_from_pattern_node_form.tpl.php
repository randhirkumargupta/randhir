<div class="custom-syndication-feed-pattern-form">
    <div class="title">
        <?php print render($form['title']); ?>
    </div>
    <div class="client-title">
        <?php print render($form['field_syndication_feed_clients']); ?>
    </div>
    <div class="content-type">
        <?php print render($form['field_syndication_feed_content']); ?>
    </div>
    <div class="feed-type">
        <?php print render($form['field_syndication_feed_type']); ?>
    </div>
    <div class="variables-and-field-container">
        <div class="variables">
            <?php print render($form['pre_define_vars']); ?>
        </div>
        <div class="xml-field">
            <?php print render($form['field_syndication_xml_formate']); ?>
        </div>
    </div>
    <div class="from-children">
        <?php print drupal_render_children($form); ?>
    </div>
</div>