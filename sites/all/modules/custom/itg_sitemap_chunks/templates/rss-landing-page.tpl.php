
<div class="what-are">
  <h2><?php echo t('What are News Feeds?') ?> </h2>
  <p><?php echo t('News feeds keep you informed when websites add new content. You get the latest headlines as soon as its published, without having to visit the websites you have taken the feed from Feeds are also known as RSS Really Simple Syndication (RSS) is an XML—based format for content distribution. RSS feeds help the user stay abreast of news as it happens and as it breaks from news sources.'); ?></p>
  <p><?php echo t('India Today RSS, the outcome of a huge network of our news sources, provides you the header of the news item and its excerpts when one subscribes to the news RSS feed.'); ?></p>
  <p><?php echo t('It grants you access or allows you to make personal use of RSS feeds. However, India Today restrains the user from putting the RSS feeds to commercial use without express conent.'); ?></p>
  <p><?php echo t('The user shall never retain any copies of the news RSS feed pages for any purpose except for personal use.') ?> </p>
</div>

<?php
$news_menu = menu_navigation_links('menu-rss-news');
$photo_menu = menu_navigation_links('menu-rss-photo');
$video_menu = menu_navigation_links('menu-rss-video');
$blog_menu = menu_navigation_links('menu-rss-blogs');
?>

<?php if (!empty($news_menu)) : ?>
  <section class="feed-type">
    <h2 class="link-heading"><?php echo t('News') ?></h2>
    <p><?php echo t('The feeds are avalibale for following sections.') ?></p>
    <?php print theme('links__menu_rss_news', array('links' => $news_menu)); ?> 
  </section>
<?php endif; ?>


<?php if (!empty($photo_menu)) : ?>
  <section class="feed-type">
    <h2 class="link-heading"><?php echo t('Photo') ?></h2>
    <p><?php echo t('The feeds are avalibale for following sections.') ?></p>
    <?php print theme('links__menu_rss_photo', array('links' => $photo_menu)); ?>
  </section>
<?php endif; ?>


<?php if (!empty($video_menu)) : ?>
  <section class="feed-type">
    <h2 class="link-heading"><?php echo t('Video') ?></h2>
    <p><?php echo t('The feeds are avalibale for following sections.') ?></p>
    <?php print theme('links__menu_rss_video', array('links' => $photo_menu)); ?>
  </section>
<?php endif; ?>

<?php if (!empty($blog_menu)) : ?>
  <section class="feed-type">
    <h2 class="link-heading"><?php echo t('All Blogs') ?></h2>
    <p><?php echo t('The feeds are avalibale for following sections.') ?></p>
    <?php print theme('links__menu_rss_blogs', array('links' => $blogs)); ?>
  </section>
<?php endif; ?>

<div class="feed-use">
  <h3><?php echo t('How Can I Use RSS?') ?></h3>
  <p> <?php echo t('News feeds keep you informed when websites add new content. You get the latest headlines as soon as its published, without having to visit the websites you have taken the feed from. Feeds are known as RSS. Really Simple Syndication (RSS) is an XML—based format for content .') ?></p>
  <div class="feed-use-sep"></div>
  <h3><?php echo t('Terms of Use') ?></h3>
  <ul>
    <li><?php echo t('News feeds keep you informed when websites add new content. You get the latest headlines as soon as its
          published. Without having to visit the websites you have taken the feed from.'); ?></li>
    <li><?php echo t('Feeds are known as RSS Really Simple Syndication (RSS) is an XML-based format for content.'); ?></li>
    <li><?php echo t('News feeds keep you informed when websites add new content. You get the latest headlines as soon as its published') ?></li>
  </ul>
</div>
