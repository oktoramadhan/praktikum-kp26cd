import {themes as prismThemes} from 'prism-react-renderer';
import type {Config} from '@docusaurus/types';
import type * as Preset from '@docusaurus/preset-classic';

// This runs in Node.js - Don't use client-side code here (browser APIs, JSX...)

const config: Config = {
  title: 'Praktikum KP C & D 2026',
  tagline: 'Materi Pembelajaran dan Penugasan Praktikum KP26',
  favicon: 'img/favicon.ico',

  // Future flags, see https://docusaurus.io/docs/api/docusaurus-config#future
  future: {
    v4: true, // Improve compatibility with the upcoming Docusaurus v4
  },

  // Set the production url of your site here
  url: 'https://my-website.vercel.app',
  // Set the /<baseUrl>/ pathname under which your site is served
  // For GitHub pages deployment, it is often '/<projectName>/'
  baseUrl: '/',

  // GitHub pages deployment config.
  // If you aren't using GitHub pages, you don't need these.
  organizationName: 'facebook', // Usually your GitHub org/user name.
  projectName: 'docusaurus', // Usually your repo name.

  onBrokenLinks: 'throw',

  // Even if you don't use internationalization, you can use this field to set
  // useful metadata like html lang. For example, if your site is Chinese, you
  // may want to replace "en" with "zh-Hans".
  i18n: {
    defaultLocale: 'en',
    locales: ['en'],
  },

  presets: [
    [
      'classic',
      {
        docs: {
          sidebarPath: './sidebars.ts',
          // Please change this to your repo.
          // Remove this to remove the "edit this page" links.

        },
        blog: {
          showReadingTime: true,
          feedOptions: {
            type: ['rss', 'atom'],
            xslt: true,
          },
          // Please change this to your repo.
          // Remove this to remove the "edit this page" links.
          editUrl:
            'https://github.com/facebook/docusaurus/tree/main/packages/create-docusaurus/templates/shared/',
          // Useful options to enforce blogging best practices
          onInlineTags: 'warn',
          onInlineAuthors: 'warn',
          onUntruncatedBlogPosts: 'warn',
        },
        theme: {
          customCss: './src/css/custom.css',
        },
      } satisfies Preset.Options,
    ],
  ],

  themeConfig: {
    // Replace with your project's social card
    image: 'img/docusaurus-social-card.jpg',
    colorMode: {
      respectPrefersColorScheme: true,
    },
    navbar: {
      title: 'KP26',
      logo: {
        alt: 'KP26 Logo',
        src: 'img/uns.svg',
      },
      items: [
        {
          type: 'docSidebar',
          sidebarId: 'tutorialSidebar',
          position: 'left',
          label: 'Materi dan Penugasan',
          className: 'materi-penugasan-link',
        },


      ],
    },
    footer: {
      style: 'dark',
      links: [
        {
          title: 'Menu',
          items: [
            {
              label: 'Materi dan Penugasan',
              to: '/docs/pengantar',
              className: 'materi-penugasan-link',
            },
          ],
        },
        {
          title: 'Media Pembelajaran',
          items: [
            {
              label: 'Google Classroom',
              href: 'https://classroom.google.com/c/NDQyNjY0NzQ1Mjk5',
            },
          ],
        },
        {
          title: 'More',
          items: [
            {
              label: 'Need Help?',
              href: 'https://api.whatsapp.com/send/?phone=6283172015644&text&type=phone_number&app_absent=0',
            },
          ],
        },
      ],
      copyright: `Copyright © ${new Date().getFullYear()} Praktikum Konsep Pemrograman, Maintained by Asisten KP26 C & D.`,
    },
    prism: {
      theme: prismThemes.github,
      darkTheme: prismThemes.dracula,
    },
  } satisfies Preset.ThemeConfig,
};

export default config;
