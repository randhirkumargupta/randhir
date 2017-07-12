<h2><?php echo t('What are News Feeds?') ?> </h2>
<div class="what-are-news-feeds">
    <p><?php echo t('News feeds keep you informed when websites add new content. You get the latest headlines as soon as its published, without having to visit the websites you have taken the feed from Feeds are also known as RSS Really Simple Syndication (RSS) is an XML—based format for content distribution. RSS feeds help the user stay abreast of news as it happens and as it breaks from news sources.'); ?></p>
    <p><?php echo t('India Today RSS, the outcome of a huge network of our news sources, provides you the header of the news item and its excerpts when one subscribes to the news RSS feed.'); ?></p>
    <p><?php echo t('It grants you access or allows you to make personal use of RSS feeds. However, India Today restrains the user from putting the RSS feeds to commercial use without express conent.'); ?></p>
    <p><?php echo t('The user shall never retain any copies of the news RSS feed pages for any purpose except for personal use.') ?> </p>
</div>

<div class="rss-menu-container">
    <?php
    $news_menu = menu_navigation_links('menu-rss-news');
    $photo_menu = menu_navigation_links('menu-rss-photo');
    $video_menu = menu_navigation_links('menu-rss-video');
    $blog_menu = menu_navigation_links('menu-rss-blogs');
    ?>
    <?php if (!empty($news_menu)) : ?>
      <h2 class="link-heading"><?php echo t('News') ?></h2>
      <p><?php echo t('The feeds are avalibale for following sections.') ?></p>
    <?php endif; ?>
    <?php
    if (!empty($news_menu)) {
      print theme('links__menu_rss_news', array('links' => $news_menu ));
    }
    ?>

    <?php if (!empty($photo_menu)) : ?>
      <h2 class="link-heading"><?php echo t('Photo') ?></h2>
      <p><?php echo t('The feeds are avalibale for following sections.') ?></p>
    <?php endif; ?>
    <?php
    if (!empty($photo_menu)) {
      print theme('links__menu_rss_photo', array('links' => $photo_menu));
    }
    ?>

    <?php if (!empty($video_menu)) : ?>
      <h2 class="link-heading"><?php echo t('Video') ?></h2>
      <p><?php echo t('The feeds are avalibale for following sections.') ?></p>
    <?php endif; ?>
    <?php
    if (!empty($video_menu)) {
      print theme('links__menu_rss_video', array('links' => $photo_menu));
    }
    ?>

    <?php if (!empty($blog_menu)) : ?>
      <h2 class="link-heading"><?php echo t('All Blogs') ?></h2>
      <p><?php echo t('The feeds are avalibale for following sections.') ?></p>
    <?php endif; ?>
    <?php
    if (!empty($blog_menu)) {
      print theme('links__menu_rss_blogs', array('links' => $blogs));
    }
    ?>
</div>

<div class="how-can-i-use">
    <h2><?php echo t('How Can I Use RSS?') ?></h2>
    <p> <?php echo t('News feeds keep you informed when websites add new content. You get the latest headlines as soon as its published, without having to visit the websites you have taken the feed from. Feeds are known as RSS. Really Simple Syndication (RSS) is an XML—based format for content .') ?></p>
    <hr/>
    <h2><?php echo t('Terms of Use') ?></h2>
    <li><?php echo t('News feeds keep you informed when websites add new content. You get the latest headlines as soon as its
        published. Without having to visit the websites you have taken the feed from.'); ?></li>
    <li><?php echo t('Feeds are known as RSS Really Simple Syndication (RSS) is an XML-based format for content.'); ?></li>
    <li><?php echo t('News feeds keep you informed when websites add new content. You get the latest headlines as soon as its published') ?></li>
</div>
