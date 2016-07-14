<?php
/**
 * @file
 * Returns the HTML for a single Drupal page.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728148
 */
?>

<?php
/**
 * Rename "Add Term" to "Add Category"
 * Remove primary local task link (Edit and manage fields links from right top side)
 */
global $base_url, $user;
if (!in_array('administrator', $user->roles)) {
    if (arg(3) == 'category_management') {
        //$action_links = '<li><a href="'.$base_url.'/admin/structure/taxonomy/category_management/add">Add Category</a></li>';
        $primary_local_tasks = '';
    }

    //Tag Management
    if (arg(3) == 'tags') {
        $primary_local_tasks = '';
        $title = 'Create Tag';
    }

    //Hide primary local task for others user(except )
    if (arg(1) == 'people' && arg(2) == 'create') {
        $primary_local_tasks = '';
    }
}
?>

<div id="page">

    <header class="header" id="header" role="banner">
        <section class="container">
            <?php if ($logo): global $base_url; ?>

                <a href="<?php print $base_url . '/cms-user-dashboard'; ?>" title="<?php print t('Home'); ?>" rel="home" class="header__logo" id="logo"><img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" class="header__logo-image" /></a>
            <?php endif; ?>

            <?php if ($site_name || $site_slogan): ?>
                <div class="header__name-and-slogan" id="name-and-slogan">
                    <?php if ($site_name): ?>
                        <h1 class="header__site-name" id="site-name">
                            <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" class="header__site-link" rel="home"><span><?php print $site_name; ?></span></a>
                        </h1>
                    <?php endif; ?>

                    <?php if ($site_slogan): ?>
                        <div class="header__site-slogan" id="site-slogan"><?php print $site_slogan; ?></div>
                    <?php endif; ?>
                </div>
            <?php endif; ?>

            <?php if ($secondary_menu): ?>
                <nav class="header__secondary-menu" id="secondary-menu" role="navigation">
                    <?php
                    print theme('links__system_secondary_menu', array(
                        'links' => $secondary_menu,
                        'attributes' => array(
                            'class' => array('links', 'inline', 'clearfix'),
                        ),
                        'heading' => array(
                            'text' => $secondary_menu_heading,
                            'level' => 'h2',
                            'class' => array('element-invisible'),
                        ),
                    ));
                    ?>
                </nav>
<?php endif; ?>
            <div class="user-role">
                <a href="<?php print $base_url . '/assigned-task-list'; ?>">
                    <i class="fa fa-bell-o"></i>
                    <dfn><?php if (function_exists('get_task_count_of_user')) {
    print get_task_count_of_user();
} ?></dfn>
                </a> 
                <span>
                    User role - 
                    <?php
                    // get role array
                    $role_display = $user->roles;
                    // skip key for authenticated user
                    //$role_display = array_slice($role_display,1);
                    unset($role_display[2]);
                    // get value in comma seprated
                    $role_display = implode(',', $role_display);
                    print $role_display;
                    ?>
                </span>
            </div>
<?php print render($page['header']); ?>
        </section>
    </header>

    <main id="main">
        <section class="container">
                    <?php print $breadcrumb; ?>
            <div id="navigation">
                    <?php if ($main_menu): ?>
                    <nav id="main-menu" role="navigation" tabindex="-1">
                        <?php
                        // This code snippet is hard to modify. We recommend turning off the
                        // "Main menu" on your sub-theme's settings form, deleting this PHP
                        // code block, and, instead, using the "Menu block" module.
                        // @see https://drupal.org/project/menu_block
                        print theme('links__system_main_menu', array(
                            'links' => $main_menu,
                            'attributes' => array(
                                'class' => array('links', 'inline', 'clearfix'),
                            ),
                            'heading' => array(
                                'text' => t('Main menu'),
                                'level' => 'h2',
                                'class' => array('element-invisible'),
                            ),
                        ));
                        ?>
                    </nav>
<?php endif; ?>
<?php print render($page['navigation']); ?>

            </div>

        </section>
        <section id="content" class="container" role="main">
            <?php print render($page['highlighted']); ?>
            <a id="main-content"></a>
            <?php
            if (arg(0) == 'node' && arg(2) == 'edit') {
                $node = node_load(arg(1));
            }

            if ((arg(0) == 'node') && ((arg(1) == 'add' && arg(2) == 'story')  || ($node->type == 'story' && arg(2) && arg(2) != 'revision')) ) {
                ?>
                <div class="action-with-title">
                    <?php print render($title_prefix); ?>
                    <?php if ($title): ?>
                    <h1 class="page__title title" id="page-title"><?php print $title; ?></h1>
                    <?php endif; ?>
                        <?php print render($title_suffix); ?>
                    <div class="top-actions">
                        <span class="btn btn-save" data-id="edit-submit">Save</span>
                        <span class="btn btn-preview" data-id="edit-preview">Preview</span>
                        <a class="btn btn-cancel mr-0" href="<?php print $base_url;  ?>/mydraft-story">Cancel</a>
                    </div>
                    <?php print render($page['form_tab']); ?>
                </div>
            <?php } else { ?>
                <?php print render($title_prefix); ?>
                <?php if ($title): ?>
                <h1 class="page__title title" id="page-title"><?php print $title; ?></h1>
                <?php endif; ?>
                <?php print render($title_suffix); ?>
                <?php print render($page['form_tab']); ?>    
            <?php } ?>

            
            <?php print $messages; ?>
            <?php print render($tabs); ?>
            <?php print render($page['help']); ?>
            <?php if ($action_links): ?>
                <ul class="action-links"><?php print render($action_links); ?></ul>
<?php endif; ?>
<?php print render($page['content']); ?>
<?php print $feed_icons; ?>
        </section>



        <?php
        // Render the sidebars to see if there's anything in them.
        $sidebar_first = render($page['sidebar_first']);
        $sidebar_second = render($page['sidebar_second']);
        ?>

                <?php if ($sidebar_first || $sidebar_second): ?>
            <aside class="sidebars">
                <span class="sidebar-trigger"><i class="fa fa-cog" aria-hidden="true"></i></span>
            <?php print $sidebar_first; ?>
    <?php print $sidebar_second; ?>
            </aside>
    <?php endif; ?>

    </main>

<?php print render($page['footer']); ?>

</div>

<?php print render($page['bottom']); ?>
